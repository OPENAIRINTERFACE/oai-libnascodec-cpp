def extract_binary_names(file_array):
    result = []
    for f in file_array :
        filename = f

        filename = filename.replace(".cpp", "")
        result += [ ( f, filename) ]
    return result