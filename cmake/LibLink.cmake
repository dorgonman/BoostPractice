#MESSAGE( STATUS "Link:        HorizonCoreStatic" )
#MESSAGE( STATUS "Link:        ${Boost_LIBRARIES}" )


target_link_libraries(${PROJECT_NAME} HorizonCoreStatic)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
   