cc_library(
    name = "nascodec-cpp",
    srcs = glob(["src/**/*.cpp"]),
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
)

cc_binary(
    name = "PDU_session_establishment_request",
    srcs = ["example/PDU_session_establishment_request.cpp"],
    deps = [":nascodec-cpp"],
)
