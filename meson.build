project('tdd_session', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

inc_dir = include_directories('include')
srcs = files('src/tennis_result_keeper.cpp')
project_dep = declare_dependency(include_directories: inc_dir, sources: srcs)

gtest_sp = subproject('gtest')
subdir('test')
