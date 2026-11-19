// Android entry point for the HELLMS native core.
//
// The game loop itself is platform independent; this file only exposes it to
// Java/Kotlin and forwards stdout/stderr to logcat so the C++ logging is
// visible with `adb logcat -s HELLMS`.

#include <jni.h>

#include <android/log.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>

#include "core/Application.hpp"

namespace {

constexpr const char* kLogTag = "HELLMS";

std::mutex g_output_mutex;
bool g_output_redirected = false;

// Android apps have no console: pipe stdout/stderr into logcat.
void pump_fd(int fd, int priority) {
    char buffer[512];
    ssize_t total = 0;

    while (true) {
        ssize_t read_bytes = ::read(fd, buffer, sizeof(buffer) - 1);
        if (read_bytes <= 0) {
            break;
        }

        for (ssize_t i = 0; i < read_bytes; ++i) {
            if (buffer[i] == '\n') {
                buffer[total] = '\0';
                if (total > 0) {
                    __android_log_write(priority, kLogTag, buffer);
                }
                total = 0;
            } else if (total < static_cast<ssize_t>(sizeof(buffer) - 1)) {
                buffer[total++] = buffer[i];
            }
        }
    }
}

void redirect_std_streams_to_logcat() {
    std::lock_guard<std::mutex> lock(g_output_mutex);
    if (g_output_redirected) {
        return;
    }

    int out_pipe[2];
    int err_pipe[2];
    if (::pipe(out_pipe) != 0 || ::pipe(err_pipe) != 0) {
        __android_log_print(ANDROID_LOG_WARN, kLogTag, "Could not create log pipes");
        return;
    }

    ::dup2(out_pipe[1], STDOUT_FILENO);
    ::dup2(err_pipe[1], STDERR_FILENO);
    ::close(out_pipe[1]);
    ::close(err_pipe[1]);

    std::setvbuf(stdout, nullptr, _IOLBF, 0);
    std::setvbuf(stderr, nullptr, _IONBF, 0);

    std::thread(pump_fd, out_pipe[0], ANDROID_LOG_INFO).detach();
    std::thread(pump_fd, err_pipe[0], ANDROID_LOG_ERROR).detach();

    g_output_redirected = true;
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "stdout/stderr redirected to logcat");
}

std::string build_info() {
    std::string info = "HELLMS Alpha 0.1 | ndk build | ";
    info += (sizeof(void*) == 8) ? "64-bit" : "32-bit";
    return info;
}

} // namespace

extern "C" {

JNIEXPORT jstring JNICALL
Java_com_hellms_game_MainActivity_nativeVersion(JNIEnv* env, jobject /*thiz*/) {
    return env->NewStringUTF(build_info().c_str());
}

JNIEXPORT jstring JNICALL
Java_com_hellms_game_MainActivity_nativeStart(JNIEnv* env, jobject /*thiz*/) {
    redirect_std_streams_to_logcat();

    __android_log_print(ANDROID_LOG_INFO, kLogTag, "%s", build_info().c_str());

    hellms::Application app;
    const int result = app.run(0, nullptr);

    char message[160];
    std::snprintf(message, sizeof(message),
                  "%s\nnative core exited with code %d\nsee: adb logcat -s HELLMS",
                  build_info().c_str(), result);
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "%s", message);

    return env->NewStringUTF(message);
}

} // extern "C"
