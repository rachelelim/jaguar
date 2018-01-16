[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 0.5 # Length of test block
  ymax = 0.5 # Width of test block
[]

[Variables]
  [./temperature]
    initial_condition = 300 # Initial temperature
  [../]
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
    type = ConstantPointSource
    variable = temperature
    value = 900
    point = '0.25 0.5'
  [../]
[]

[BCs]
  #[./inlet_temperature]
  #  type = DirichletBC
  #  variable = temperature
  #  boundary = left
  #  value = 350 # (K)
  #[../]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = bottom
    value = 300 # (K)
  [../]
[]

[Materials]
  [./Ti64]
    type = GenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '6.7 0.526 4430' # W/m*K, J/kg-K, kg/m^3 @ 296K
  [../]
[]

[Problem]
  type = FEProblem
  coord_type = RZ
  rz_coord_axis = X
[]

[Executioner]
  type = Transient
  num_steps = 10
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
