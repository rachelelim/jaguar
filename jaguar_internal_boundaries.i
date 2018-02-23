[Mesh]
  file = 2d_moving.msh
[]

[MeshModifiers]
  [./layer_1_sideset]
    type = SideSetsBetweenSubdomains
    master_block = layer_1
    paired_block = layer_2
    new_boundary = layer_1_top
  [../]
  [./layer_2_sideset]
    type = SideSetsBetweenSubdomains
    master_block = layer_2
    paired_block = layer_3
    new_boundary = layer_2_top
  [../]
  [./layer_3_sideset]
    type = SideSetsBetweenSubdomains
    master_block = layer_3
    paired_block = layer_4
    new_boundary = layer_3_top
  [../]
  # [./layer_1_id]
  #   type = AssignSubdomainID
  #   subdomain_id = 11
  # [../]
  # [./layer_2_id]
  #   type = AssignSubdomainID
  #   subdomain_id = 10
  # [../]
  # [./layer_3_id]
  #   type = AssignSubdomainID
  #   subdomain_id = 9
  # [../]
  # [./layer_4_id]
  #   type = AssignSubdomainID
  #   subdomain_id = 8
  # [../]
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
    # diffusion_coefficient = 6.7 # Thermal conductivity W/m*K * 1e3
    variable = temperature
  [../]
  [./heat_conduction_time_derivative]
    type = HeatConductionTimeDerivative
    # density_name = 0.00443 # g/mm^3
    # specific_heat = 526 # J/g-K * 1e3
    variable = temperature
  [../]
[]

[DiracKernels]
  [./point_heat_source]
    type = MovingDirac2d
#    type = ConstantPointSource
    variable = temperature
    value = 1900
    point = '0 0 0'
  [../]
[]

# [InterfaceKernels]
#   [./layer1]
#     type =
#   [../]
# []

[BCs]
  [./outlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = bottom_outlet
    value = 296 # (K)
  [../]
  # [./layer_1_top_bc]
  #   type = DirichletBC
  #   variable = temperature
  #   boundary = layer_1_top
  #   value = 296
  # [../]
  # [./layer_2_top_bc]
  #   type = DirichletBC
  #   variable = temperature
  #   boundary = layer_2_top
  #   value = 296
  # [../]
  # [./layer_3_top_bc]
  #   type = DirichletBC
  #   variable = temperature
  #   boundary = layer_3_top
  #   value = 296
  # [../]
 # [./heat_influx]
 #    type = NeumannBC
 #    variable = temperature
 #    boundary =
 #    value = 20
 #  [../]
[]

# [Controls]
  # Disable the NeumannBC between layers
  # [./period_0]
  #   type = TimePeriod
  #   disable_objects = 'BCs::layer_1_top_bc'
  #   start_time = 4
  #   end_time = 16
  #   execute_on = 'initial timestep_begin'
  # [../]
  # [./period_1]
  #   type = TimePeriod
  #   disable_objects = 'BCs::layer_2_top_bc'
  #   start_time = 8
  #   end_time = 16
  #   execute_on = 'initial timestep_begin'
  # [../]
  # [./period_2]
  #   type = TimePeriod
  #   disable_objects = 'BCs::layer_3_top_bc'
  #   start_time = 12
  #   end_time = 16
  #   execute_on = 'initial timestep_begin'
  # [../]

  # Disable the layers
  # [./period_0]
  #   type = TimePeriod
  #   disable_objects = 'MeshModifiers::layer_2_id MeshModifiers::layer_3_id MeshModifiers::layer_4_id'
  #   start_time = 0
  #   end_time = 4
  #   execute_on = 'initial timestep_begin'
  # [../]
  # [./period_1]
  #   type = TimePeriod
  #   enable_objects = 'MeshModifiers::layer_2_id'
  #   disable_objects = 'MeshModifiers::layer_3_id MeshModifiers::layer_4_id'
  #   start_time = 4
  #   end_time = 8
  # [../]
  # [./period_2]
  #   type = TimePeriod
  #   enable_objects = 'MeshModifiers::layer_2_id MeshModifiers::layer_3_id'
  #   disable_objects = 'MeshModifiers::layer_4_id'
  #   start_time = 8
  #   end_time = 12
  # [../]
  # [./period_3]
  #   type = TimePeriod
  #   enable_objects = 'MeshModifiers::layer_2_id MeshModifiers::layer_3_id MeshModifiers::layer_4_id'
  #   start_time = 12
  #   end_time = 16
  # [../]
# []

[Materials]
  [./Ti64_layer2_conduct]
    type = ParsedMaterial
    block = layer_2
    output_properties = 'thermal_conductivity'
    function = if(t>4,6.7,0)
    # prop_names = 'thermal_conductivity specific_heat density'
    # prop_values = '6.7 0.526 4430' # W/m*K * 1e3, J/kg-K * 1e3, kg/m^3 @ 296K
  [../]
  [./Ti64_layer2]
    type = GenericConstantMaterial
    block = layer_2
    prop_names = 'specific_heat density'
    prop_values = '0.526 4430' # W/m*K * 1e3, J/kg-K * 1e3, kg/m^3 @ 296K
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
  num_steps = 80
  end_time = 16
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
