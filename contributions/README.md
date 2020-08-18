# How to contribute to the IAR RISC-V GD32V Eval Board repository

## Opening a pull request

You can read more about pull requests at [GitHub Documentation][about-pull-requests].

### GitHub pull request basic workflow 
1. Create a personal [Fork][github-create-fork] of the [IAR RISC-V GD32V Eval Board repository][gd32v-repo]
*   If you have done this previously, you can always [sync your fork to the upstream][sync-fork-url].

2. Clone the forked repository to your local machine
```
$ git clone https://github.com/<your-github-account>/iar-risc-v-gd32v-eval.git
```

3. Create `<your-local-new-branch-name>` in which you will work on
```
$ git branch <your-local-new-branch-name>
```
* If contributing with new projects to this repository, the branch name should match the new project name.
  
4. Change the newly created branch 
```
$ git checkout <your-local-new-branch-name>
```

5. Perform the desired changes
*   Read our [**coding guidelines**][coding-guidelines-url]. 
*   If contributing with new projects to the repository, use the [Contributions Project Template][project-template].  

6. Commit the changes 
```
$ git add .

$ git commit -m <commit-message>
```
*   Keep your git commit history **clean** and **precise.** Refer to the section about "Git commit messages" in the [**coding guidelines**][coding-guidelines-url].

7. Push the changes to yours repository's origin
```
$ git push
```

8. Back to your forked GitHub repository page and, finally, perform a pull request
*   Keep the title **short** and provide a **clear** description about what your pull request does.
*   If your commit fixes a reported issue (for example #123), add the following message to the commit `Closes #123`.

[coding-guidelines-url]: CODING_GUIDELINES.md
[project-template]: https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/contributions/template/README.md
[about-pull-requests]: https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-requests
[github-create-fork]: https://guides.github.com/activities/forking/
[gd32v-repo]: https://github.com/IARSystems/iar-risc-v-gd32v-eval
[sync-fork-url]: https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork
