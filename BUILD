load("//:libnas-cpp.bzl", "extract_binary_names")

# build library

cc_library(
    name = "nascodec-cpp",
    srcs = glob(["src/**/*.cpp"]),
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
    copts = ["-Werror"]
)

# build examples

[ cc_binary(
    name = files[1],
    srcs = [files[0]] + glob(["example/include/**/*.h"]),
    deps = [":nascodec-cpp"],
    linkstatic = True,
    copts = ["-Werror"]
        )
for files in extract_binary_names(glob(["example/**/*.cpp"])) ]

# test examples

[ sh_test(
    name = files[1] + "_test",
    srcs = [ ":" + files[1]],
    timeout = "short",
) for files in extract_binary_names(glob(["example/**/*.cpp"])) ]

# build tests

[ cc_binary(
    name = files[1],
    srcs = [files[0]] + glob(["test/include/**/*.h"]),
    deps = [":nascodec-cpp"],
    linkstatic = True,
    copts = ["-Werror", "-Itest/include"]
        )
for files in extract_binary_names(glob(["test/**/*.cpp"])) ]

# execute tests

[ sh_test(
    name = files[1] + "_test",
    srcs = [ ":" + files[1]],
    timeout = "short",
) for files in extract_binary_names(glob(["test/**/*.cpp"])) ]