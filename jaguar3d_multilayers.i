[Mesh]
  file = 3d_moving_v4.msh
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
    scaling = 1e3 # Multiply the PDE by the scaling number, use when the residual is too small/large to avoid computational inaccuracy
  [../]
[]

[Functions]
# Assign different thermal conductivity along time to materials in different layers
[./material_layer2]
  type = ParsedFunction
  value = 'if(t>=0.05,0.0067,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer3]
  type = ParsedFunction
  value = 'if(t>=0.10,0.0067,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer4]
  type = ParsedFunction
  value = 'if(t>=0.15,0.0067,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer5]
  type = ParsedFunction
  value = 'if(t>=0.20,0.0067,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer6]
  type = ParsedFunction
  value = 'if(t>=0.25,0.0067,0.0000)' # Thermal conductivity W/mm*K
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
    type = MovingDirac3d_multilayers
    variable = temperature
    value = 150
    point = '0 0.2 0.2'
  [../]
[]

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = 'bottom_outlet'
    value = 296 # (K)
  [../]
[]

[Materials]
  # Specific heat and density
  [./Ti64_base]
    type = GenericConstantMaterial
    block = base
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer1]
    type = GenericConstantMaterial
    block = layer_1
    prop_names = 'thermal_conductivity specific_heat density'
    prop_values = '0.0067 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer2]
    type = GenericConstantMaterial
    block = layer_2
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer3]
    type = GenericConstantMaterial
    block = layer_3
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer4]
    type = GenericConstantMaterial
    block = layer_4
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer5]
    type = GenericConstantMaterial
    block = layer_5
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  [./Ti64_layer6]
    type = GenericConstantMaterial
    block = layer_6
    prop_names = 'specific_heat density'
    prop_values = '0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  [../]
  #Inactive layer thermal conductivity
  [./Ti64_layer2_conduct]
    type = GenericFunctionMaterial
    block = layer_2
    prop_names = 'thermal_conductivity'
    prop_values = material_layer2
  [../]
  [./Ti64_layer3_conduct]
    type = GenericFunctionMaterial
    block = layer_3
    prop_names = 'thermal_conductivity'
    prop_values = material_layer3
  [../]
  [./Ti64_layer4_conduct]
    type = GenericFunctionMaterial
    block = layer_4
    prop_names = 'thermal_conductivity'
    prop_values = material_layer4
  [../]
  [./Ti64_layer5_conduct]
    type = GenericFunctionMaterial
    block = layer_5
    prop_names = 'thermal_conductivity'
    prop_values = material_layer5
  [../]
  [./Ti64_layer6_conduct]
    type = GenericFunctionMaterial
    block = layer_6
    prop_names = 'thermal_conductivity'
    prop_values = material_layer6
  [../]
[]

[Problem]
  type = FEProblem
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-5
  l_tol = 1e-13 # Use to control the number of linear iteration, can help to lower the non-linear residual when it is not converge
  start_time = 0.0
  num_steps = 1200
  solve_type = 'PJFNK' # Preconditioning Jacobian Free Newton-Keylov
  petsc_options_iname = '-pc_type -pc_hypre_type' #pc: Preconditioning // Hypre: parallel high performance preconditioners (library)
  petsc_options_value = 'hypre boomeramg' # mg: multigrid
  [./TimeStepper]
    type = FunctionDT
    time_t  = '0.0     0.003   0.008   0.045   0.05     0.053    0.058   0.095   0.100    0.103    0.108   0.145   0.15     0.153    0.158   0.195   0.200    0.203    0.208   0.245   0.25     0.253'
    time_dt = '0.00005 0.00005 0.0005  0.0005  0.00005  0.00005  0.0005  0.0005  0.00005  0.00005  0.0005  0.0005  0.00005  0.00005  0.0005  0.0005  0.00005  0.00005  0.0005  0.0005  0.00005  0.00005'
  [../]
[]


[Outputs]
  exodus = true
[]
