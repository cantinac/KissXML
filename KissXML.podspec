
Pod::Spec.new do |s|
  s.name    = 'KissXML'
  s.version = '5.5'

  s.ios.deployment_target = '8.0'
  s.osx.deployment_target = '10.9'

  s.author   = { 'Robbie Hanson' => 'robbiehanson@deusty.com' }
  s.license  = { :type => 'MIT', :file => 'LICENSE.txt' }
  s.homepage = 'https://github.com/robbiehanson/KissXML'
  s.summary  = "KissXML provides a drop-in replacement for Apple's NSXML class culster in environments without NSXML (e.g. iOS)."

  s.source = { :git => 'https://github.com/robbiehanson/KissXML.git', :tag => s.version.to_s }

  s.source_files         = "KissXML/**/*.{h,m}"
  s.private_header_files = "KissXML/Private/*.h"

  s.requires_arc        = true
  s.libraries           = 'xml2'
  s.pod_target_xcconfig = { 'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"' }
end
