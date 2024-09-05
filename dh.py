import subprocess
from datetime import datetime, timedelta
import os

def run_command(command, env=None):
    """Run a shell command with optional environment variables."""
    result = subprocess.run(command, shell=True, capture_output=True, text=True, env=env)
    if result.returncode != 0:
        print(f"Error: {result.stderr}")
    return result

def make_commit(commit_message, commit_date):
    """Create a fake commit with the specified message and date."""
    # Create or modify a dummy file to change its content
    with open("fake_file.txt", "a") as file:
        file.write(f"Commit made on {commit_date}\n")
    
    # Add changes to the staging area
    run_command("git add .")
    
    # Set commit date using environment variables
    env = os.environ.copy()
    env["GIT_AUTHOR_DATE"] = commit_date
    env["GIT_COMMITTER_DATE"] = commit_date

    # Make the commit with the specified date and commit message
    run_command(f'git commit -m "{commit_message}"', env=env)

def generate_commits_for_date_range(start_date, end_date, commit_message):
    """Generate fake commits for each day in the specified date range with the given commit message."""
    current_date = start_date

    while current_date <= end_date:
        # Format the date for the commit
        formatted_date = current_date.strftime('%Y-%m-%dT%H:%M:%S')
        print(f"Creating commit on {current_date.strftime('%Y-%m-%d')} with message: {commit_message}")

        # Create the commit with the given message
        make_commit(commit_message, formatted_date)

        # Move to the next day
        current_date += timedelta(days=1)

if __name__ == "__main__":
    # Initialize a Git repository if not already done
    if not os.path.exists(".git"):
        run_command("git init")

    # Define the date range (from 6th October 2024 to 15th October 2024)
    start_date = datetime.strptime("2024-09-06", "%Y-%m-%d")
    end_date = datetime.strptime("2024-10-15", "%Y-%m-%d")

    # Define the specific commit message
    commit_message = "commit"

    # Generate commits for the specified date range with the commit message
    generate_commits_for_date_range(start_date, end_date, commit_message)
