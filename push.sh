echo "- simple_shell" >> README.md
git init
git add *
git commit -m "Fix error after remove old repo "
git branch -M main
git remote add origin git@github.com:mohamedahmed-cloud/simple_shell.git
git push -u origin main
