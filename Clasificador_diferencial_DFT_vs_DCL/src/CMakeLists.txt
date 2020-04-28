INCLUDE_DIRECTORIES("${PROJECT_INCLUDE_DIR}")


SET(COMMON_SRCS 
	Clasificador_diferencial_DFT_vs_DCL.c
	Clasificador_diferencial_DFT_vs_DCL_emxAPI.c
	Clasificador_diferencial_DFT_vs_DCL_emxutil.c
	Clasificador_diferencial_DFT_vs_DCL_initialize.c
	Clasificador_diferencial_DFT_vs_DCL_terminate.c
    aggregatePredict.c
    any.c
    CompactClassificationTree.c
    main.c
    predictOneWithCache.c
    repmat.c
    CompactEnsemble.c
    updateCache.c
    rtGetInf.c
    rtGetNaN.c
    rt_nonfinite.c)
				
ADD_EXECUTABLE(main main.c ${COMMON_SRCS})

TARGET_LINK_LIBRARIES(main m)
