[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 200
  ny = 200
  xmax = 1 # Length of test block
  ymax = 1 # Width of test block
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
    scaling = 1e-1

  [../]
[]

[Kernels]
  [./heat_conduction]
    type = HeatConduction
    diffusion_coefficient = 6.7 # Thermal conductivity W/m*K * 1e3
    variable = temperature
  [../]
  [./heat_conduction_time_derivative]
    type = HeatConductionTimeDerivative
    density_name = 0.00443 # g/mm^3
    specific_heat = 526 # J/g-K * 1e3
    variable = temperature
  [../]
[]

[DiracKernels]
  [./point_heat_source]
#    type = MovingDirac
    type = ConstantPointSource
    variable = temperature
    value = 135
    point = '0.5 0.5 0'
  [../]
[]

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = bottom
    value = 296 # (K)
  [../]

 # [./heat_influx]
 #    type = NeumannBC
 #    variable = temperature
 #    boundary =
 #    value = 20
 #  [../]
[]

[Materials]
  [./Ti64]
    type = GenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.0043' # W/mm*K * 1e3, J/g-K * 1e3, g/mm^3 @ 296K
  [../]
[]

[Problem]
  type = FEProblem
  coord_type = RZ
  rz_coord_axis = X
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-10
  l_tol = 1e-08
  num_steps = 20
  end_time = 0.001
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
