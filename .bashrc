################################## Construct PATH variable ##################################

winpath=$(echo $MSYS2_WINPATH | tr ";" "\n" | sed -e 's/\\/\\\\/g' | xargs -I {} cygpath -u {})
unixpath=''

# Set delimiter to new line
IFS=$'\n'

for pth in $winpath; do unixpath+=$(echo $pth)":"; done

export PATH=$(echo $PATH:$unixpath | sed -e 's/:$//g')
unset IFS
unset unixpath
unset winpath

################################# Constructed PATH variable #################################