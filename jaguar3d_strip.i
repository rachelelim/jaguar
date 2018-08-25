[Mesh]
  file = 3d_moving_v2.msh
[]

[Variables]
  [./temperature]
    initial_condition = 296 # Initial temperature
    scaling = 1e3 # Multiply the PDE by the scaling number, use when the residual is too small/large to avoid computational inaccuracy
  [../]
[]

[Functions]
  #Strip heat source
    # [./heatsource_layer1]
    #   type = ParsedFunction
    #   value = 'if(t <= 0.003,150,1)'
    # [../]
    # [./heatsource_layer2]
    #   type = ParsedFunction
    #   value = 'if(t >= 60.0031 & t <= 60.0061,150,1)'
    # [../]
    # [./heatsource_layer3]
    #   type = ParsedFunction
    #   value = 'if(t >= 120.0062 & t <= 120.0092,150,1)'
    # [../]
  # [./heatsource_layer4]
  #   type = ParsedFunction
  #   value = 'if(t >= 180 & t <= 180.003,150,1)'
  # [../]
  # [./heatsource_layer5]
  #   type = ParsedFunction
  #   value = 'if(t >= 240 & t <= 240.003,150,1)'
  # [../]
  # [./heatsource_layer6]
  #   type = ParsedFunction
  #   value = 'if(t >= 300 & t <= 300.003,150,1)'
  # [../]
  # [./heatsource_layer7]
  #   type = ParsedFunction
  #   value = 'if(t >= 360 & t <= 360.003,150,1)'
  # [../]
  # [./heatsource_layer8]
  #   type = ParsedFunction
  #   value = 'if(t >= 420 & t <= 420.003,150,1)'
  # [../]
  # [./heatsource_layer9]
  #   type = ParsedFunction
  #   value = 'if(t >= 480 & t <= 480.003,150,1)'
  # [../]
  # [./heatsource_layer10]
  #   type = ParsedFunction
  #   value = 'if(t >= 540 & t <= 540.003,150,1)'
  # [../]
# Assign different thermal conductivity along time to materials in different layers
[./material_layer2]
  type = ParsedFunction
  value = 'if(t>=60.00305,0.0067,0.0000)' # Thermal conductivity W/mm*K
[../]
[./material_layer3]
  type = ParsedFunction
  value = 'if(t>=120.00615,0.0067,0.0000)' # Thermal conductivity W/mm*K
[../]
# Assign different thermal conductivity along time to powder in different layers
# [./material_powder_layer2]
#   type = ParsedFunction
#   value = 'if(t>=60.00305,0.0027,0.0000)' # Thermal conductivity W/mm*K
# [../]
# [./material_powder_layer3]
#   type = ParsedFunction
#   value = 'if(t>=120.00615,0.0027,0.0000)' # Thermal conductivity W/mm*K
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
  # [./heatsource_layer1]
  #   type = HeatSource
  #   # enable = false
  #   block = layer_1c
  #   variable = temperature
  #   function = heatsource_layer1
  #   # value = 150
  # [../]
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
  #Test material
  # [./Ti64]
  #   type = GenericConstantMaterial
  #   prop_names = 'thermal_conductivity specific_heat density'
  #   prop_values = '0.0067 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  # [../]

  # Update conductivity of materials along simulation time
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
  #Thermal conductivity of powder -- Ref: powder bed electron-beam-melting additive manufacturing: powder characterization, process simulation ... Xibing Gong 2.7W/mK
  # [./Ti64_layer1l_powder]
  #   type = GenericConstantMaterial
  #   block = layer_1l
  #   prop_names = 'thermal_conductivity specific_heat density'
  #   prop_values = '0.0027 0.526 0.0043' # W/mm*K, J/g-K, g/mm^3 @ 296K
  # [../]
[]

[Problem]
  type = FEProblem
  # coord_type = RZ
  # rz_coord_axis = X
[]

[Executioner]
  type = Transient
  nl_rel_tol = 1e-5
  l_tol = 1e-13 # Use to control the number of linear iteration, can help to lower the non-linear residual when it is not converge
  start_time = 0.0
  end_time = 0.8
  num_steps = 600
  solve_type = 'PJFNK' # Preconditioning Jacobian Free Newton-Keylov
  petsc_options_iname = '-pc_type -pc_hypre_type' #pc: Preconditioning // Hypre: parallel high performance preconditioners (library)
  petsc_options_value = 'hypre boomeramg' # mg: multigrid
  [./TimeStepper]
    type = FunctionDT
    # time_t  = '0 0.003 0.00305 60.00305 60.0031 60.0061 60.00615 120.00615 120.0062 120.0092'
    # time_dt = '0.00005 0.00005 1 1 0.00005 0.00005 1 1 0.00005 0.00005'
    time_t  = '0.0     0.003   1.00305 60.00305 60.0031  60.0061 61.00615 120.00615 120.0062 120.0092'
    time_dt = '0.00005 0.00005 1.0     1.0      0.00005  0.00005 1.0      1.0       0.00005  0.00005'
  [../]
[]

# [Controls]
#   [./period_0]
#     type = TimePeriod
#     disable_objects = 'Kernels::heatsource'
#     start_time = '0'
#     end_time = '0.000195'
#     execute_on = 'initial timestep_begin'
#   [../]
#   [./period_1]
#     type = TimePeriod
#     disable_objects = 'Kernels::heatsource0'
#     enable_objects = '*::heatsource'
#     start_time = '0.0002'
#     end_time = '0.000595'
#     execute_on = 'initial timestep_begin'
#   [../]
#   [./period_2]
#     type = TimePeriod
#     disable_objects = 'Kernels::heatsource'
#     enable_objects = '*::heatsource0'
#     start_time = '0.0006'
#     execute_on = 'initial timestep_begin'
#   [../]
# []

[Outputs]
  exodus = true
[]
