import React, { useEffect, useRef } from 'react';
import { gsap } from 'gsap';
import { ScrollTrigger } from 'gsap/dist/ScrollTrigger';

import styles from './Section.module.scss';
import DownButton from './components/DownButton/DownButton';

gsap.registerPlugin(ScrollTrigger);

const Section = ({
  image, headline, goToSectionRef, showArrow, theme,
}) => {
  const headlineRef = useRef();

  useEffect(() => {
    gsap.fromTo(headlineRef.current, { autoAlpha: 0, y: 40 }, {
      y: 0,
      autoAlpha: 1,
      duration: 1,

      scrollTrigger: {
        scroller: '.container',
        trigger: headlineRef.current,
        start: 'top 60%',
        end: 'bottom 0%',
        toggleActions: 'play none restart reverse',
      },
    });
    return () => {};
  }, []);

  return (
    <div className={`${theme === 'light' ? styles.light : styles.dark} ${styles.section}`}>
      <div className={styles.copy}>
        <h2 ref={headlineRef}>{headline}</h2>
      </div>
      {image && (<img className={styles.image} src={image} />)}
      {showArrow && (<DownButton goToSectionRef={goToSectionRef} theme={theme}/>)}
    </div>
  );
};
export default Section;
