INCLUDE_DIRECTORIES("${PROJECT_INCLUDE_DIR}")


SET(COMMON_SRCS 
	Clasificador_diferencial_EA_vs_DFT.c
	Clasificador_diferencial_EA_vs_DFT_emxAPI.c
	Clasificador_diferencial_EA_vs_DFT_emxutil.c
	Clasificador_diferencial_EA_vs_DFT_initialize.c
	Clasificador_diferencial_EA_vs_DFT_terminate.c
     any.c
    bsxfun.c
    ClassificationKNN.c
    createkds.c
    kdsearchfun.c
    knnsearch.c
    log2.c
    main.c
    repmat.c
    sort1.c
    sortIdx.c
    sum.c
    rtGetInf.c
    rtGetNaN.c
    rt_nonfinite.c)
				
ADD_EXECUTABLE(main main.c ${COMMON_SRCS})

TARGET_LINK_LIBRARIES(main m)
