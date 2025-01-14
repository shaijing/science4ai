py_dep = py.dependency()
py.extension_module(
    'mod',
    sources: ['mod.c'],
    include_directories: [dllinclude],
    dependencies: [py_dep],
    link_with: dlldep,
    install: true,
    subdir: 'science4ai',
)