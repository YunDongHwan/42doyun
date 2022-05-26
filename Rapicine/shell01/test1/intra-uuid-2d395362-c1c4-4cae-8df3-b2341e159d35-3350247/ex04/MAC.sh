ifconfig -a | grep '\tether' | sed 's/[[:blank:]]// g' | sed 's/ether//'
