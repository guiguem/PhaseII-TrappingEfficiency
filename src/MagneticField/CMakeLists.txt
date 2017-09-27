###########
# control #
###########

set( headers
    MagneticField.h
)

set( sources
    MagneticField.cpp
)

###########
# library #
###########


pbuilder_library( MagneticField sources "" )
target_link_libraries (MagneticField  ${ROOT_LIBRARIES} )

pbuilder_install_headers( ${headers} )

