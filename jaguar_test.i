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

[AuxVariables]
  [./a]
    initial_condition = 0
  [../]
  [./b]
    initial_condition = 0
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
#    type = MovingDirac
    type = ConstantPointSource
    variable = temperature
    value = 135
    point = '0.5 0.5 0'
  [../]
[]

[AuxKernels]
  [./phase]
    type = ParsedAux
    variable = a
    args = temperature
    function = 'if(temperature>=1916,1,0)'
  [../]
  [./accumulate_phase]
    type = AccumulateAux
    variable = b
    accumulate_from_variable = a
    execute_on = timestep_begin
  [../]
[]

[BCs]
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
