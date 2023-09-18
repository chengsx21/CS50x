import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 2 and len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    with open(sys.argv[1], "r", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        database = list(reader)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r", encoding="utf-8") as f:
        sequence = f.read()

    # Find longest match of each STR in DNA sequence
    longest_match_list = []
    for key in database[0].keys():
        if key != "name":
            longest_match_list.append(str(longest_match(sequence, key)))

    # Check database for matching profiles
    for _, data in enumerate(database):
        if list(data.values())[1:] == longest_match_list:
            print(data["name"])
            return
    print("No match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)
    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0
        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        # Update most consecutive matches found
        longest_run = max(longest_run, count)
    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
