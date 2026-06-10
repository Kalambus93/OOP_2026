import std;
import download_text;
import normalize;
import counting_unique_words;
import frequent_repetition;

int main()
{
    std::println("-----------------------------------\n"
                 "\tЛР №: 5\n"
                 "\tГруппа: 6112\n"
                 "\tАвтор: Трофимов Максим\n"
                 "\tВариант: 28\n"
                 "-----------------------------------");

    std::println("Название: Twenty Thousand Leagues under the Sea by Jules Verne");
    std::vector<std::string> main_vector_lines = DownloadText("../../../../labs/lab5/text.txt");
    main_vector_lines = Normalize(main_vector_lines);
    std::println("\nКоличество слов в тексте: {} слов", main_vector_lines.size());

    std::unordered_set<std::string> stop_words = {
        "a", "an", "the",

        "about", "above", "across", "after", "against", "along", "among", "around",
        "at", "before", "behind", "below", "beneath", "beside", "between", "beyond",
        "by", "down", "during", "except", "for", "from", "given", "in", "inside",
        "into", "like", "near", "of", "off", "on", "onto", "out", "outside", "over",
        "past", "through", "throughout", "to", "toward", "under", "until", "up",
        "upon", "with", "within", "without",

        "i", "you", "he", "she", "it", "we", "they",
        "me", "him", "her", "us", "them",
        "my", "your", "his", "her", "its", "our", "their",
        "mine", "yours", "hers", "ours", "theirs",
        "this", "that", "these", "those",
        "some", "any", "no", "every", "all", "both", "each", "few", "many", "most",
        "other", "such", "which", "what", "who", "whom", "whose",

        "and", "or", "but", "so", "for", "nor", "yet",
        "if", "then", "else", "when", "where", "which", "while", "whilst",
        "as", "like", "than", "that", "whether",

        "be", "am", "are", "is", "was", "were", "being", "been",
        "have", "has", "had", "having", "do", "does", "did", "doing",
        "will", "would", "shall", "should", "may", "might", "must", "could",

        "very", "really", "quite", "rather", "somewhat", "just", "even",
        "only", "so", "too", "also", "well", "then", "now", "here", "there",

        "not", "no", "yes", "ok", "okay",
        "get", "got", "gotten", "getting",
        "make", "made", "making", "do", "did", "done", "doing"};

    std::println("\nНезначимые слова: {}", stop_words);

    unsigned long int count_unique_words = Counter(main_vector_lines, stop_words);
    std::println("\nКоличество уникальных слов: {}", count_unique_words);
    auto frequent_word = FrequentRepetition(main_vector_lines, stop_words);
    std::println("\n Это/и слово/а: {} встречается наиболее часто. А именно {} раз", frequent_word._max_words, frequent_word._count);

    return 0;
}