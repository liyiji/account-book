
TEMPLATE = subdirs
CONFIG += ordered

LIST = lib_all app_all

for( item, LIST ) : exists( $$item ) : SUBDIRS += $$item
