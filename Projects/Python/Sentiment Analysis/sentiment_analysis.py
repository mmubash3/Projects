
def compute_tweets(TWEET_FILE,KEYWORDS_FILE):
    #will be required in order to remove punctuation
    import string
    #function made in order to remove punctuation and make the string lowercase
    def format_string(s):
      for x in string.punctuation:
        s=s.replace(x,"")
        s=s.lower()
      return s

    #co-ordinates(latitude,longitude) required to determine location
    P1 = (49.189787, -67.444574)
    P2 = (24.660845, -67.444574)
    P3 = (49.189787, -87.518395)
    P4 = (24.660845, -87.518395)
    P5 = (49.189787, -101.998892)
    P6 = (24.660845, -101.998892)
    P7 = (49.189787, -115.236428)
    P8 = (24.660845, -115.236428)
    P9 = (49.189787, -125.242264)
    P10 = (24.660845, -125.242264)

    #try is used so that incase the wrong file is inputted then it gives an error message
    try:
        KEYWORDS=open(KEYWORDS_FILE,'r')
    except IOError:
        list_of_tuples=[]
        return list_of_tuples
    #lists that store the keywords co-orespoding to their values
    rating_1=[]
    rating_2=[]
    rating_3=[]
    rating_4=[]
    rating_5=[]
    rating_6=[]
    rating_7=[]
    rating_8=[]
    rating_9=[]
    rating_10=[]

    for line in KEYWORDS.readlines():
        word=line.split(",")
        if int(word[1]) == 1:
            rating_1.append(word[0])
        elif int(word[1]) == 2:
            rating_2.append(word[0])
        elif int(word[1]) == 3:
            rating_3.append(word[0])
        elif int(word[1]) == 4:
            rating_4.append(word[0])
        elif int(word[1]) == 5:
            rating_5.append(word[0])
        elif int(word[1]) == 6:
            rating_6.append(word[0])
        elif int(word[1]) == 7:
            rating_7.append(word[0])
        elif int(word[1]) == 8:
            rating_8.append(word[0])
        elif int(word[1]) == 9:
            rating_9.append(word[0])
        elif int(word[1]) == 10:
            rating_10.append(word[0])

    #function created in order to measure the happiness score of each tweet
    #this makes sure that if there is a key file inserted with keys having values from anywhere between 1-10 it'd still be able to calculate it
    def happiness_score(tweet):
        no_of_positive_words=0
        value_of_tweet=0
        for x in tweet:
            if x in rating_1:
                no_of_positive_words+=1
                value_of_tweet+=1
            elif x in rating_2:
                no_of_positive_words+=1
                value_of_tweet+=2
            elif x in rating_3:
                no_of_positive_words+=1
                value_of_tweet+=3
            elif x in rating_4:
                no_of_positive_words+=1
                value_of_tweet+=4
            elif x in rating_5:
                no_of_positive_words+=1
                value_of_tweet+=5
            elif x in rating_6:
                no_of_positive_words+=1
                value_of_tweet+=6
            elif x in rating_7:
                no_of_positive_words+=1
                value_of_tweet+=7
            elif x in rating_8:
                no_of_positive_words+=1
                value_of_tweet+=8
            elif x in rating_9:
                no_of_positive_words+=1
                value_of_tweet+=9
            elif x in rating_10:
                no_of_positive_words+=1
                value_of_tweet+=10
            score=[value_of_tweet,no_of_positive_words]
        return (score)

    #value required for etz
    total_happiness_score_etz=0
    total_no_of_tweets_with_key_etz=0
    total_no_of_tweets_etz=0


    #values required for ctz
    total_happiness_score_ctz=0
    total_no_of_tweets_with_key_ctz=0
    total_no_of_tweets_ctz=0


    #values required for mtz
    total_happiness_score_mtz=0
    total_no_of_tweets_with_key_mtz=0
    total_no_of_tweets_mtz=0


    #values required for ptz
    total_happiness_score_ptz=0
    total_no_of_tweets_with_key_ptz=0
    total_no_of_tweets_ptz=0



    #try is used so that incase the wrong file is inputted then it gives an error message
    try:
        TWEETS=open(TWEET_FILE,'r')
    except IOError:
        list_of_tuples=[]
        return list_of_tuples
    for line in TWEETS:
        word=line.split()
        #this works to remove the brackets around the co-ordinates & turn them into floats so that they can be used to allocate the tweet to the right location
        latitude=word[0].replace('[','').replace(',','')
        longitude=word[1].replace(']','').replace(',','')
        latitude=float(latitude)
        longitude=float(longitude)

        # EASTERN TIME ZONE etz
        if (latitude <= P1[0] and latitude >= P2[0]) and (longitude <= P1[1] and longitude>= P3[1]):
            #used in order to keep count of total tweets
            total_no_of_tweets_etz+=1
            list_of_words=[]
            #this is the place where all the words get formatted and the happiness score is calculated
            for each_item in word:
                formated_item=format_string(each_item)
                list_of_words.append(formated_item)
            happiness_per_tweet=happiness_score(list_of_words)
            #try is used as at times there are no key words hence it comes up as 0 therefore we can get through 0 division error
            try:
                happiness_per_tweet=int(happiness_per_tweet[0])/int(happiness_per_tweet[1])
            except ZeroDivisionError:
                happiness_per_tweet=0
            if happiness_per_tweet>0:
                total_no_of_tweets_with_key_etz+=1
            total_happiness_score_etz+=happiness_per_tweet

          # CENTRAL TIME ZONE ctz
        elif (latitude <= P1[0] and latitude >= P2[0]) and (longitude <= P3[1] and longitude>= P5[1]):
            total_no_of_tweets_ctz+=1
            list_of_words=[]
            for each_item in word:
                formated_item=format_string(each_item)
                list_of_words.append(formated_item)
            happiness_per_tweet=happiness_score(list_of_words)
            try:
                happiness_per_tweet=int(happiness_per_tweet[0])/int(happiness_per_tweet[1])
            except ZeroDivisionError:
                happiness_per_tweet=0
            if happiness_per_tweet>0:
                total_no_of_tweets_with_key_ctz+=1
            total_happiness_score_ctz+=happiness_per_tweet

            # MOUNTAIN TIME ZONE mtz
        elif (latitude <= P1[0] and latitude >= P2[0]) and (longitude <= P5[1] and longitude>= P7[1]):
            total_no_of_tweets_mtz+=1
            list_of_words=[]
            for each_item in word:
                formated_item=format_string(each_item)
                list_of_words.append(formated_item)
            happiness_per_tweet=happiness_score(list_of_words)
            try:
                happiness_per_tweet=int(happiness_per_tweet[0])/int(happiness_per_tweet[1])
            except ZeroDivisionError:
                happiness_per_tweet=0
            if happiness_per_tweet>0:
                total_no_of_tweets_with_key_mtz+=1
            total_happiness_score_mtz+=happiness_per_tweet

           #PACIFIC TIME ZONE ptz
        elif (latitude <= P1[0] and latitude >= P2[0]) and (longitude <= P7[1] and longitude>= P9[1]):
            total_no_of_tweets_ptz+=1
            list_of_words=[]
            for each_item in word:
                formated_item=format_string(each_item)
                list_of_words.append(formated_item)
            happiness_per_tweet=happiness_score(list_of_words)
            try:
                happiness_per_tweet=int(happiness_per_tweet[0])/int(happiness_per_tweet[1])
            except ZeroDivisionError:
                happiness_per_tweet=0
            if happiness_per_tweet>0:
                total_no_of_tweets_with_key_ptz+=1
            total_happiness_score_ptz+=happiness_per_tweet

    #try is used as at times there are no tweets with key words so in order to tackle the error from dividing with 0
    try:
        happiness_value_ctz=total_happiness_score_ctz/total_no_of_tweets_with_key_ctz
    except ZeroDivisionError:
        happiness_value_ctz=0
    try:
        happiness_value_etz=total_happiness_score_etz/total_no_of_tweets_with_key_etz
    except ZeroDivisionError:
        happiness_value_etz=0
    try:
        happiness_value_mtz=total_happiness_score_mtz/total_no_of_tweets_with_key_mtz
    except ZeroDivisionError:
        happiness_value_mtz=0
    try:
        happiness_value_ptz=total_happiness_score_ptz/total_no_of_tweets_with_key_ptz
    except ZeroDivisionError:
        happiness_value_ptz=0

    #the final values that will be stored in tuples after the program is run
    final_values_for_eastern_time_zone=(happiness_value_etz,total_no_of_tweets_with_key_etz,total_no_of_tweets_etz)
    final_values_for_central_time_zone=(happiness_value_ctz,total_no_of_tweets_with_key_ctz,total_no_of_tweets_ctz)
    final_values_for_mountain_time_zone=(happiness_value_mtz,total_no_of_tweets_with_key_mtz,total_no_of_tweets_mtz)
    final_values_for_pacific_time_zone=(happiness_value_ptz,total_no_of_tweets_with_key_ptz,total_no_of_tweets_ptz)

    #the list of tuples which can be returned to the main file
    list_of_tuples=[final_values_for_eastern_time_zone,final_values_for_central_time_zone,final_values_for_mountain_time_zone,final_values_for_pacific_time_zone]

    return list_of_tuples

