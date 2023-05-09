import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize
from heapq import nlargest

def summarize(text, num_sentences):
    # Tokenize the text into individual sentences
    sentences = sent_tokenize(text)
    
    # Tokenize each sentence into individual words
    words = word_tokenize(text.lower())
    
    # Remove stop words
    stop_words = set(stopwords.words('english'))
    filtered_words = [word for word in words if word.casefold() not in stop_words]
    
    # Calculate word frequency
    word_freq = {}
    for word in filtered_words:
        if word in word_freq:
            word_freq[word] += 1
        else:
            word_freq[word] = 1
    
    # Calculate sentence scores based on word frequency
    sentence_scores = {}
    for sentence in sentences:
        for word in word_tokenize(sentence.lower()):
            if word in word_freq:
                if len(sentence.split(' ')) < 30:
                    if sentence in sentence_scores:
                        sentence_scores[sentence] += word_freq[word]
                    else:
                        sentence_scores[sentence] = word_freq[word]
    
    # Get the top N sentences with the highest scores
    summary_sentences = nlargest(num_sentences, sentence_scores, key=sentence_scores.get)
    
    # Return the summary as a string
    summary = ' '.join(summary_sentences)
    return summary



# To use the summarizer, you can pass in a long text and the desired number of sentences for the summary:

text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce mattis orci sit amet ante tincidunt, ut efficitur lorem maximus. Proin vitae nunc vel tellus suscipit efficitur. Duis id velit sit amet nulla commodo laoreet a a purus. Sed euismod risus ut diam convallis, eget faucibus mauris eleifend. Sed quis eros velit. Suspendisse quis ipsum et dolor tincidunt mollis vitae eget velit. Nulla nec consequat odio. Nullam vehicula lobortis libero, ac pulvinar sapien dictum vel. Nullam at ex turpis. Sed in enim quis mi tincidunt interdum."

summary = summarize(text, 2)
print(summary)
