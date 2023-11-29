git add .
git commit -m "nothing"
git reset $(git commit-tree HEAD^{tree} -m "Versions don't matter in this repo :)")
git push -f