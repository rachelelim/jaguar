[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 400
  ny = 100
  nz = 100
  xmax = 4 # Length of test block
  ymax = 1 # Width of test block
  zmax = 1 # Thickness of test block
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
  [../]
[]

[Functions]
 # [./location_x]
 #   type = ParsedFunction
 #   value = '0.0 + t'
 #   # vars = 'alpha'
 #   # vals = '0.05'
 # [../]
 # [./location_y]
 #   type = ParsedFunction
 #   value = '0.25'
 #   # vars = 'alpha'
 #   # vals = '0.05'
 # [../]
 # [./location_z]
 #   type = ParsedFunction
 #   value = '0.0'
 #   # vars = 'alpha'
 #   # vals = '0.05'
 # [../]
[]

[Kernels]
  [./heat_conduction]
    type = HeatConduction
    variable = temperature
  [../]
  [./heat_conduction_time_derivative]
    type = HeatConductionTimeDerivative
    variable = temperature
  [../]
[]

[DiracKernels]
  [./point_heat_source]
    type = MovingDirac
    variable = temperature
    value = 3560
    point = '0 0 0'
  [../]
[]

[BCs]
#  [./inlet_temperature]
#    type = DirichletBC
#    variable = temperature
#    boundary = top
#    value = 600 # (K)
#    function = heatsource_func
#  [../]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = bottom
    value = 296 # (K)
  [../]
[]

[Materials]
  [./Ti64]
    type = GenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.00443' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
[]

[Problem]
  type = FEProblem
#  coord_type = RZ
#  rz_coord_axis = X
[]

[Executioner]
  type = Transient
#  nl_rel_tol = 1e-08
#  nl_abs_tol = 1e-15
#  l_tol = 1e-05
  num_steps = 20
  end_time = 0.004
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
