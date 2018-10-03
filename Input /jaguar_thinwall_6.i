[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 300
  ny = 80
  nz = 50
  xmax = 3 # Length of test block
  ymax = 0.8 # Width of test block
  zmax = 0.5 # Thickness of test block
[]

[Variables]
  [./temperature]
    initial_condition = 356 # Initial temperature
  [../]
[]

[AuxVariables]
  [./a] #For 3d visualization purpose
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
  [./point_heat_source_raster]
    type = MovingDirac3dHatch_IN718_500_raster
    variable = temperature
    value = 142.5
    point = '0.2 0.506 0.495'
  [../]
  [./point_heat_source_contour1]
    type = MovingDirac3dHatch_IN718_500_contour1
    variable = temperature
    value = 69
    point = '0 0 0'
  [../]
  [./point_heat_source_contour2]
    type = MovingDirac3dHatch_IN718_500_contour2
    variable = temperature
    value = 40
    point = '0 0 0'
  [../]
[]

[AuxKernels]
  [./phase]
    type = ParsedAux
    variable = a
    args = temperature
    function = 'if(temperature>=1609,1,0)'
  [../]
  [./accumulate_phase] # Calculate the total time a cell > Tmelt
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
    boundary = 'back'
    value = 356 # (K)
  [../]
[]

[Controls]
  [./period_0]
  type = TimePeriod
  disable_objects = 'DiracKernels::point_heat_source_contour1'
  start_time = 0
  end_time = 0.003985607
  execute_on = 'initial timestep_begin'
  [../]
  [./period_1]
  type = TimePeriod
  disable_objects = 'DiracKernels::point_heat_source_contour2'
  start_time = 0
  end_time = 0.018022479
  execute_on = 'initial timestep_begin'
  [../]
 []

[Materials]
  [./IN718]
    type = GenericConstantMaterial
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0124 0.435 0.008193' # W/mm*K, J/g-K, g/mm^3 @ 296K
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
  num_steps = 900
  end_time = 0.026
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
