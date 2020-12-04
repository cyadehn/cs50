# git ssh AWS ide setup: https://github.com/hstatsep/ide50

source ~/bash/.bash_commands
source ~/bash/.bash_aliases
source ~/bash/.bash_profile

alias mk="makeit && go"
function makeit()
{
    current=${PWD##*/}
    make $current
}
function go()
{
    current=${PWD##*/}
    ./$current
}
