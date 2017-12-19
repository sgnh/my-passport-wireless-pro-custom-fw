#!/bin/bash

CMD=$@

$CMD
_RETURN_VALUE=$?
echo "RETURN_VALUE=$_RETURN_VALUE"

