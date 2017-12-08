import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import warnings
warnings.filterwarnings("ignore")
import wordcloud
import re
from sqlalchemy import create_engine
from collections import Counter
from sklearn.feature_extraction.text import CountVectorizer

questions = pd.read_csv('../data/processing/questions.csv')
solutions = pd.read_csv('output.csv')

def clean_statement(x):
    x = re.sub('-', ' ', x)
    x = re.sub('[,|.|?|\n]|\t', '', x)
    x = re.sub('n\'t', ' not', x)
    x = re.sub('All submissions for this problem are available', '', x)
    x = re.sub('Read problems statements in Mandarin Chinese|Russian|as well', '', x)
    x = re.sub('and|Vietnamese', '', x)
    return x

questions['statement'] = [clean_statement(x) for x in questions.statement.values]

# print(Counter(questions.level).most_common())

#cloud = wordcloud.WordCloud(background_color='black', max_font_size=60, relative_scaling=.5).generate(' '.join(questions.statement))
#plt.figure(figsize=(20,10))
#plt.axis('off')
#plt.imshow(cloud);
#plt.show()

#solutions['StatusGroup'] = solutions.Status.str.split('(').str[0]
#g = sns.factorplot("StatusGroup", data=solutions, kind="count")
#g.set_xticklabels(rotation=90)
#plt.show()

#sol = solutions
#sol = sol.loc[(sol.StatusGroup == 'wrong answer')|(sol.StatusGroup == 'accepted')]
#Counter(sol.StatusGroup)
