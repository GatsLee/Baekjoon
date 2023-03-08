find . -name ".DS*"
find . -name ".DS*" -delete
echo -e "\n------.DS* files deleted------\n"
git add *
git status
echo -e "\nR U ready to turn in your work you've been working?\n"
read answer
if [ ${answer} == "yes" -o ${answer} == "y" ]; then
    git commit -m "joon-lee"
    git push --set-upstream origin main
else
    echo "Well then, prepare for your next battle!"
fi
