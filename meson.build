project('tdd_session', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

inc_dir = include_directories('include')
json_sp = subproject('json')
json_dep = json_sp.get_variable('nlohmann_json_dep')
project_dep = declare_dependency(include_directories: inc_dir, dependencies: [json_dep])

gtest_sp = subproject('gtest')
subdir('test')
