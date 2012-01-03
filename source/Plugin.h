//
//  Plugin.h
//  MrsWatson
//
//  Created by Nik Reiman on 1/3/12.
//  Copyright (c) 2012 Teragon Audio. All rights reserved.
//

#import "CharString.h"
#import "SampleBuffer.h"

#ifndef MrsWatson_Plugin_h
#define MrsWatson_Plugin_h

typedef enum {
  PLUGIN_TYPE_INVALID,
  PLUGIN_TYPE_VST_2X,
} PluginType;

typedef bool (*OpenPluginFunc)(void*, const CharString pluginName);
typedef void (*PluginProcessFunc)(void*, SampleBuffer);

typedef struct {
  PluginType pluginType;
  CharString pluginName;

  OpenPluginFunc open;
  PluginProcessFunc process;

  void* extraData;
} PluginMembers;

typedef PluginMembers* Plugin;

PluginType guessPluginType(CharString pluginName);
Plugin newPlugin(PluginType pluginType);
void freePlugin(Plugin plugin);

#endif