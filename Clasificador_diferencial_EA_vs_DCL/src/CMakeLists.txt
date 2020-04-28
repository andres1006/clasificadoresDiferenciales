INCLUDE_DIRECTORIES("${PROJECT_INCLUDE_DIR}")


SET(COMMON_SRCS 
	Clasificador_diferencial_EA_vs_DCL.c
	Clasificador_diferencial_EA_vs_DCL_emxAPI.c
	Clasificador_diferencial_EA_vs_DCL_emxutil.c
	Clasificador_diferencial_EA_vs_DCL_initialize.c
	Clasificador_diferencial_EA_vs_DCL_terminate.c
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
