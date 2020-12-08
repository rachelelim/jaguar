[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 200
  ny = 40
  nz = 60
  xmax = 2 # Length of test block
  ymax = 0.4 # Width of test block
  zmax = 0.6 # Thickness of test block
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
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
  [./heat_source]
    type = singlebead
    variable = temperature
    value = 208
    point = '0.1 0.2 0.395'
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
    value = 296 # (K)
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
  num_steps = 95
  end_time = 0.002375
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
