[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 625
  ny = 125
  xmax = 0.005 # Length of test block
  ymax = 0.001 # Width of test block

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
    type = MovingDirac2d
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
    prop_values = '6.7 526 4430' # W/m*K, J/kg-K, kg/m^3 @ 296K
  [../]
[]

[Problem]
  type = FEProblem
  coord_type = RZ
  rz_coord_axis = X
[]

[Executioner]
  type = Transient
  num_steps = 100
  end_time = 0.005
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
