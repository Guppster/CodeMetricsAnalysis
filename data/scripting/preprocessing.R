solutions <- read.csv("../original/solutions.csv")

familyC <- solutions[grepl("^C", solutions$Language) & solutions$Language != "CLPS" & solutions$Language != "CLOJ" & solutions$Language != "CAML" & solutions$Language != "C#" & solutions$Language != "C++ 4.ewplaintext/11967296",]

familyC <- droplevels(familyC)

write.table(familyC, "../processing/solutionsCFamily.csv", sep=",") 

multmerge = function(mypath)
{
    filenames = list.files( path = mypath, full.names=TRUE )
    datalist = lapply(filenames, function(x){read.csv(file=x,header=T)})
    Reduce(function(x,y) {merge(x,y)}, datalist)
}

dataset = multmerge("processing/")

write.table(dataset, "../processing/halfprocessed.csv", sep=",") 

str(dataset)
table(dataset$Languge)


# Convert to character type for merge operation
final$Solutions <- as.character(final$Solutions)
final$Solutions.y <- as.character(final$Solutions.y)
final$Solutions.x <- as.character(final$Solutions.x)

# Merge the 3 code samples into the same column
final$Code <- final$Solutions.x

# Check if the current row isnt null at solutions.y column, if it isnt, copy its value to Code column
final$Code[!is.na(final$Solutions.y)] = final$Solutions.y[!is.na(final$Solutions.y)]
final$Code[!is.na(final$Solutions)] = final$Solutions[!is.na(final$Solutions)]

# Check for no null values in Code column 
sum(grepl(' NA ', final$Code))

# Write out final preprocessed file
write.csv(final, file = "final.csv")
