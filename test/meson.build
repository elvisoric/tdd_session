gtest_main = files('gtest_main.cpp')

gtest_srcs = [gtest_main,
  'foo_test.cpp'
  ]

gtest_dep = gtest_sp.get_variable('gtest_dep')
gmock_dep = gtest_sp.get_variable('gmock_dep')

gtest_exec = executable('TddSessionTests', gtest_srcs, 
  dependencies :[gtest_dep, gmock_dep, project_dep])

test('TDD session tests', gtest_exec)
