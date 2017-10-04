###########
# control #
###########

set( headers
)

set( sources
    TrappingEfficiency.cpp
)

###########
# library #
###########


pbuilder_library( TrappingEfficiency sources "" )
target_link_libraries (TrappingEfficiency  ${ROOT_LIBRARIES} MagneticField ToolBox)

pbuilder_install_headers( ${headers} )

