project('light', 'cpp',
    version : '0.0.1',
    license : 'GPL3',
    default_options : ['cpp_std=c++17']
)

## Dependencies
curl_dep = dependency('libcurl', version:'>=8.5.0')
json_dep = dependency('jsoncpp', version:'>=1.9.4')
cli_dep = dependency('opencxx-cli', version:'>=0.0.4')


add_global_arguments(language : 'cpp')

inc = include_directories('include')
subdir('src')