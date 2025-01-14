project(
  'science4ai',
  'c',
  'cpp',
  default_options: [
    'c_std=c11',
    'cpp_std=c++20',
  ],
)
# 获取顶层 meson.build 的路径
project_root = meson.project_source_root()

# 打印路径（仅用于调试）
# message('顶层 meson.build 路径: ' + project_root)
py = import('python').find_installation(pure: false)
subdir('dll')
subdir('science4ai')