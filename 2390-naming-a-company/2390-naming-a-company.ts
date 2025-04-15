function distinctNames(ideas: string[]): number {
    // Group idea by their initials.
    const initialGroup: Set<string>[] = Array.from({ length: 26 }, () => new Set<string>());

    for (const idea of ideas) {
        const initialIndex = idea.charCodeAt(0) - 'a'.charCodeAt(0);
        initialGroup[initialIndex].add(idea.substring(1));
    }

    let answer = 0;

    // Calculate number of valid names from every pair of groups.
    for (let i = 0; i < 25; ++i) {
        for (let j = i + 1; j < 26; ++j) {
            let numOfMutual = 0;

            for (const ideaA of initialGroup[i]) {
                if (initialGroup[j].has(ideaA)) {
                    numOfMutual++;
                }
            }

            // Valid names are only from distinct suffixes in both groups.
            // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
            answer += 2 * (initialGroup[i].size - numOfMutual) * (initialGroup[j].size - numOfMutual);
        }
    }

    return answer;
}
