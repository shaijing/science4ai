
dllinclude = include_directories('include')
dlldep = library(
    'science4ai',
    'src/science4ai.c',
    include_directories: dllinclude,
    version: '1.0.0',
    soversion: '',
    #c_args:['-fPIC','-DDLL_EXPORTS'],
    c_args: ['/DDLL_EXPORTS'],
    name_prefix: '',
    install: true,
    install_dir: py.get_install_dir() / 'science4ai',
)