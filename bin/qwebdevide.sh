#!/bin/bash
 
export LD_PRELOAD=$1/libMimeData.so, $1/libPluginManager.so 
$1/qwebdevide