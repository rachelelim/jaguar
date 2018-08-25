[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 300
  ny = 60
  nz = 60
  xmax = 3 # Length of test block
  ymax = 0.6 # Width of test block
  zmax = 0.6 # Thickness of test block
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
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
    type = MovingDirac3dHatch
    variable = temperature
    value = 135
    point = '0.2 0.15 0.595'
  [../]
[]

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = 'back'
    value = 296 # (K)
  [../]
[]

[Materials]
  [./Ti64]
    type = GenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
[]

[Problem]
  type = FEProblem
#  coord_type = RZ
#  rz_coord_axis = X
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-10
  l_tol = 1e-08
  num_steps = 140
  end_time = 0.0035
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
