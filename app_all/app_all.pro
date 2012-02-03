
TEMPLATE = subdirs
CONFIG += ordered

LIST = accountBook convertF1T2

for( item, LIST ) : exists( $$item ) : SUBDIRS += $$item
