
export VJ_BASE_DIR=/usr/local/pkg/vrjuggler-2.0.1-linux-suse93-i686
export VJ_DEPS_DIR=/usr/local/pkg/vrjuggler-2.0.1-suse93-i686-deps
export VJ_CONFIG_FILES=${VJ_BASE_DIR}/share/vrjuggler/data/configFiles
export VJ_CFG_PATH=${VJ_BASE_DIR}/share/vrjuggler/data/configFiles

export VPR_DEBUG_NOTIFY_LEVEL=2
export VPR_DEBUG_ENABLE=1

export JDK_HOME=/usr/java2

export PATH=${VJ_BASE_DIR}/bin:${OSG_HOME}/bin:${PATH}
if[-z "$LD_LIBRARY_PATH"];
export LD_LIBRARY_PATH=${VJ_BASE_DIR}/lib:${VJ_DEPS_DIR}/lib
else
export LD_LIBRARY_PATH=${VJ_BASE_DIR}/lib:${VJ_DEPS_DIR}/lib:$LD_LIBRARY_PATH
fi


