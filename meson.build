project('light', 'cpp',
    version : '0.0.1',
    license : 'GPL3',
    default_options : ['cpp_std=c++17']
)

## Dependencies
curl_dep = dependency('libcurl')
cli_dep = dependency('opencxx-cli')


add_global_arguments(language : 'cpp')

inc = include_directories('include')
subdir('src')