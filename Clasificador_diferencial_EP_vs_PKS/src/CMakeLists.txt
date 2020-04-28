INCLUDE_DIRECTORIES("${PROJECT_INCLUDE_DIR}")


SET(COMMON_SRCS
    Clasificador_diferencial_EP_vs_PKS.c
	Clasificador_diferencial_EP_vs_PKS_emxAPI.c
	Clasificador_diferencial_EP_vs_PKS_emxutil.c
	Clasificador_diferencial_EP_vs_PKS_initialize.c
	Clasificador_diferencial_EP_vs_PKS_terminate.c
    CompactSVM.c
    Linear.c
    main.c
    rtGetInf.c
    rtGetNaN.c
    rt_nonfinite.c)
				
ADD_EXECUTABLE(main main.c ${COMMON_SRCS})

TARGET_LINK_LIBRARIES(main m)
