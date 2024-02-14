Creating a comprehensive cheat sheet for managing a GitHub project collaboratively can streamline your workflow significantly. Here's an organized cheat sheet that covers a variety of actions you'll take while working on your project, including both Git command line and GitHub CLI (gh) commands where applicable. This cheat sheet assumes you have Git and GitHub CLI installed and are somewhat familiar with the basics of version control.

NOTE: generated this with chatGPT, need to verify contents but should be pretty boilerplate stuff so it should be safe

### Setting Up & Cloning Repositories

#### **Initialize a New Repository**
- **Git:** `git init`
- **GitHub CLI:** Not applicable directly, but after creating on GitHub, clone it.

#### **Clone an Existing Repository**
- **Git:** `git clone <repository-url>`
- **GitHub CLI:** `gh repo clone <repository-owner>/<repository-name>`

### Managing Branches

#### **List All Branches**
- **Git:** `git branch -a`
- **GitHub CLI:** `gh repo view --web`, then navigate to branches (for a visual GUI approach).

#### **Create a New Branch**
- **Git:** `git checkout -b <branch-name>`
- **GitHub CLI:** `gh pr create --base <target-branch> --head <your-new-branch>` (implicitly creates a new branch when starting a pull request).

#### **Switch Between Branches**
- **Git:** `git checkout <branch-name>`
- **GitHub CLI:** Not directly applicable. Use Git command.

#### **Delete a Branch**
- **Git:** `git branch -d <branch-name>` (safe delete), `git branch -D <branch-name>` (force delete)
- **GitHub CLI:** `gh api -X DELETE repos/:owner/:repo/git/refs/heads/<branch-name>`

### Making Changes & Committing

#### **Staging Changes**
- **Git:** `git add <file-path>` or `git add .` (to add all changes)
- **GitHub CLI:** Not applicable. Use Git command.

#### **Committing Changes**
- **Git:** `git commit -m "commit message"`
- **GitHub CLI:** Not applicable. Use Git command.

### Pushing & Pulling

#### **Push Changes to Remote**
- **Git:** `git push origin <branch-name>`
- **GitHub CLI:** Not directly applicable. Use Git command.

#### **Pull Latest Changes from Remote**
- **Git:** `git pull origin <branch-name>`
- **GitHub CLI:** Not directly applicable. Use Git command.

### Managing Pull Requests

#### **Create a Pull Request**
- **Git:** Not directly applicable. Use GitHub web interface or GitHub CLI.
- **GitHub CLI:** `gh pr create --base <base-branch> --head <feature-branch> --title "PR Title" --body "PR description"`

#### **List Open Pull Requests**
- **Git:** Not directly applicable. Use GitHub web interface or GitHub CLI.
- **GitHub CLI:** `gh pr list`

#### **Checkout a Pull Request Locally**
- **Git:** Not directly applicable without additional configuration.
- **GitHub CLI:** `gh pr checkout <pr-number>`

#### **Merge a Pull Request**
- **Git:** Not directly applicable. Use GitHub web interface or GitHub CLI.
- **GitHub CLI:** `gh pr merge <pr-number>`

### Working with Issues

#### **List Open Issues**
- **Git:** Not directly applicable. Use GitHub web interface or GitHub CLI.
- **GitHub CLI:** `gh issue list`

#### **Create an Issue**
- **Git:** Not directly applicable. Use GitHub web interface or GitHub CLI.
- **GitHub CLI:** `gh issue create --title "Issue Title" --body "Issue description"`

### Viewing Repository Status & History

#### **View Status of Your Working Directory**
- **Git:** `git status`
- **GitHub CLI:** Not applicable. Use Git command.

#### **View Commit History**
- **Git:** `git log`
- **GitHub CLI:** Not directly applicable. Use Git command.

### Miscellaneous

#### **Stashing Changes**
- **Git:** `git stash` (stash changes), `git stash pop` (apply stashed changes)
- **GitHub CLI:** Not applicable. Use Git command.

#### **Comparing Changes**
- **Git:** `git diff` (before staging), `git diff --staged` (after staging)
- **GitHub CLI:** Not directly applicable. Use Git command.

This cheat sheet covers the essential commands for managing your project using Git and GitHub CLI. Remember, the GitHub CLI (`gh`) complements Git by providing GitHub-specific functionality, such as managing pull requests and issues, that isn't available directly through Git commands. Always ensure you're working on the correct branch and have the latest changes synced to avoid merge conflicts.
