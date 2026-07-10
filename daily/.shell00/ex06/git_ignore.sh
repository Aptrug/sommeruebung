git status --ignored --untracked-files=all --porcelain -z | tr '\0' '\n' | sed -n 's/^!! //p'
