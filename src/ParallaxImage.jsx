import React from 'react';

const ParallaxImage = ({
  caption, image, id, below,
}) => (
  <div className="parallax-image">
    <div className="background-image" id={id} style={{ backgroundImage: `url("${image}")` }}>
      {caption ? <div className="caption">{caption}</div> : null}
    </div>
    {below ? (
      <div className="paragraph-text">
        <p>{below}</p>
      </div>
    ) : null}
  </div>
);

export default ParallaxImage;
